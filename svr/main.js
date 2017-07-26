
global.port = getRandomInt(1025, 65534);
var svr = require('./svr.js');
var main_url = "http://127.0.0.1:" + global.port +"/";
window.location.href = main_url;  

var win = nw.Window.get();
win.on('close', function() {
    nw.App.quit();
    this.close(true);
});
function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}   