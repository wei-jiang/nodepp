const dgram = require('dgram');
const _ = require("underscore");
const hat = require('hat');
const udp = dgram.createSocket('udp4');
let cpp_back = require('./build/Release/cpp_back');
let pending_pack = {};
let node_udp_port = port + 1, cxx_udp_port = port + 2;

global.call_cxx_promise = _.throttle(function (data) {
    logger.info('in start_service');
    return new Promise((resolve, reject) => {
        let uid = hat();
        data.uid = uid;
        const buff = Buffer.from(JSON.stringify(data));
        pending_pack[uid] = res => {
            delete res.uid;
            resolve(res);
            delete pending_pack[uid];
        }
        udp.send(buff, cxx_udp_port, 'localhost', (err) => {
            if (err) {
                logger.info('start_service set request failed');
                reject(err);
            }
        });
    });
}, 1000);
global.call_cxx_cb = _.throttle(function (data, cb) {

    let uid = hat();
    data.uid = uid;
    const buff = Buffer.from(JSON.stringify(data));
    pending_pack[uid] = res => {
        delete res.uid;
        cb(res);
    }
    udp.send(buff, cxx_udp_port, 'localhost', (err) => {
        if (err) {
            logger.info('reg_evt set request failed');
            cb(err);
        }
    });

}, 1000);


udp.on('error', (err) => {
    logger.info(`udp server error:\n${err.stack}`);
    udp.close();
});

udp.on('message', (msg, rinfo) => {
    logger.info(`udp server got: ${msg} from ${rinfo.address}:${rinfo.port}`);
    msg = msg.toString('utf8');
    logger.info(msg);
    let res = JSON.parse(msg);
    let res_handler = pending_pack[res.uid];
    if (res_handler) {
        res_handler(res);
    } else {
        logger.info('res_handler is null');
    }
});

exports.init = cfg => {
    udp.on('listening', () => {
        var address = udp.address();
        logger.info(`udp server listening ${address.address}:${address.port}`);
        cfg = cfg || {
            node_udp_port,
            cxx_udp_port
        }
        cpp_back.init(JSON.stringify(cfg));
    });
    udp.bind(node_udp_port, '127.0.0.1');
}


