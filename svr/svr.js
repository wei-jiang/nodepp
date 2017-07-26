
var fs = require('fs');
var app = require('express')();
var server = require('http').Server(app);
var favicon = require('serve-favicon');
var io = require('socket.io')(server);
var _ = require("underscore");
var bodyParser = require('body-parser');
var iconv_lite = require('iconv-lite');
let winston = require('winston');

var logDir = 'log';
// Create the log directory if it does not exist
if (!fs.existsSync(logDir)) {
  fs.mkdirSync(logDir);
}
global.logger = new (winston.Logger)({
  transports: [
    new (require('winston-daily-rotate-file'))({
      filename: logDir + '/-cpp_back.log',
      timestamp: function() { 
        return ( new Date() ).toLocaleString(); 
      },
      datePattern: 'yyyy-MM-dd',
      prepend: true
    })
  ]
});
app.use( bodyParser.json() );       // to support JSON-encoded bodies
app.use(bodyParser.urlencoded({     // to support URL-encoded bodies
  extended: true
}));
// app.use(favicon(__dirname + '/public/favicon.ico'));
server.listen(port);
app.use(require('express').static(__dirname + '/public'));
var cur_sock;
io.on('connection', function(socket){    
  cur_sock = socket;
  logger.info( "backend on connection..." ); 
  socket.on('event', function(data) {
    logger.info( "socket on event, data=" + JSON.stringify(data) ); 
        
  });
});
require('./inter_cpp').init();