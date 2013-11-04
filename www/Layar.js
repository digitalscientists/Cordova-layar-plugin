window.launchLayarVision = function(show, hide) {

	function isFunction(f){
       return (typeof f !== "undefined") && (typeof f === "function");
    }
    
    if(isFunction(show)) show();
    setTimeout(function(){cordova.exec(null, null, "Layar", "launchLayarVision", [])}, 1);
    if(isFunction(hide)) setTimeout(hide, 3000);
    
};