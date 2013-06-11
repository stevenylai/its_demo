createXmlHttpRequest = function () {
	if (window.XMLHttpRequest) {
		var oHttp=new XMLHttpRequest();
		return oHttp;
	} else if (window.ActiveXObject) {
		var versions = [
			"MSXML2.XmlHttp.6.0",
			"MSXML2.XmlHttp.3.0",
		];
		for (var i=0; i<versions.length; i++) {
			try {
				var oHttp=new ActiveXObject(version[i]);
				return oHttp;
			} catch (error) {}
		}
	}
	return null;
}

function Ajax() {
	this.RAW=1;
	this.requireLogin=false;
	this.responseType=this.RAW;
	this.request=createXmlHttpRequest();
	this.ondone=null;
}
Ajax.prototype.post = function (sUrl) {
	tmpAjax=this;
	this.request.open("GET", sUrl, true);
	this.request.onreadystatechange=handle;
	this.request.send(null);
}
tmpAjax=null;
handle = function () {
	if (tmpAjax.request.readyState==4) {
		if (tmpAjax.request.status==200) {
			tmpAjax.ondone(tmpAjax.request.responseText);
		}
	}
}
