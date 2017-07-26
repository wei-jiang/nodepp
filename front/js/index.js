
var gui = require('nw.gui');

var iconv_lite = require('iconv-lite');
var serialPort = require("serialport");

var SerialPort = serialPort.SerialPort;
var cpp_back = require("./build/Release/cpp_back");

var wwwRoot = window.location.href;
var cur_page = wwwRoot.slice( wwwRoot.lastIndexOf("/") + 1 );
if (wwwRoot.substr(wwwRoot.lenght - 1, 1) != "/") {
    wwwRoot = wwwRoot.substr(0, wwwRoot.lastIndexOf("/"));
}
var sock = io(wwwRoot);
sock.on('connect',function() {
    console.log("on_connected to local server");     
});

console.log(cpp_back);
function test() {
    console.log('invoke test()')
    global.call_cxx_promise({cmd:'test'}).then( data => console.log(data) );
}
//只返回一次的用promise，返回多次的用callback
function reg_evt() {
    let cnt = 0;
    global.call_cxx_cb( {cmd:'sch_task', tid:79}, data => console.log(cnt++, data) );
}
function unreg_evt() {
    global.call_cxx_cb({cmd:'unsch_task', tid:79}, data => console.log(data) );
}
var vm = new Vue({
    el: 'body',
    data: {
        logs:[],
        need_pass:false
    },    
    computed: {
        dev_id: function () {
            return ("device_id");
        }
    },
    methods: {
        check: function(){

        },
        inspect: function(){

        }
    } 
})