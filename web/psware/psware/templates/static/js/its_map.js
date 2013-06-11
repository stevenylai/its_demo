function ITSMap (imageSrc, canvas) {
	this.imageURL=imageSrc;

	this.jg=new jsGraphics(canvas);

	this.selected=new Array();
	this.notified=new Array();

	this.roads=new Array();
	this.roads[0]=new Array();
	this.roads[0][0]=47;
	this.roads[0][1]=378;
	this.roads[0][2]=205;
	this.roads[0][3]=416;
	this.roads[1]=new Array();
	this.roads[1][0]=278;
	this.roads[1][1]=378;
	this.roads[1][2]=340;
	this.roads[1][3]=416;
	this.roads[2]=new Array();
	this.roads[2][0]=410;
	this.roads[2][1]=376;
	this.roads[2][2]=516;
	this.roads[2][3]=414;
	this.roads[3]=new Array();
	this.roads[3][0]=596;
	this.roads[3][1]=374;
	this.roads[3][2]=710;
	this.roads[3][3]=412;
	this.roads[4]=new Array();
	this.roads[4][0]=216;
	this.roads[4][1]=422;
	this.roads[4][2]=268;
	this.roads[4][3]=508;
	this.roads[5]=new Array();
	this.roads[5][0]=350;
	this.roads[5][1]=422;
	this.roads[5][2]=400;
	this.roads[5][3]=508;
	this.roads[6]=new Array();
	this.roads[6][0]=528;
	this.roads[6][1]=422;
	this.roads[6][2]=578;
	this.roads[6][3]=508;
	this.roads[7]=new Array();
	this.roads[7][0]=720;
	this.roads[7][1]=422;
	this.roads[7][2]=752;
	this.roads[7][3]=508;
	this.roads[8]=new Array();
	this.roads[8][0]=282;
	this.roads[8][1]=515;
	this.roads[8][2]=340;
	this.roads[8][3]=539;
	this.roads[9]=new Array();
	this.roads[9][0]=410;
	this.roads[9][1]=515;
	this.roads[9][2]=515;
	this.roads[9][3]=539;
	this.roads[10]=new Array();
	this.roads[10][0]=590;
	this.roads[10][1]=515;
	this.roads[10][2]=710;
	this.roads[10][3]=539;

}
ITSMap.prototype.getSelected = function (roadID) {
		for (var i=0; i<this.selected.length; i++) {
			if (this.selected[i]==roadID)
				return i;
		}
		return -1;
	}
ITSMap.prototype.getNotified = function (roadID) {
		for (var i=0; i<this.notified.length; i++) {
			if (this.notified[i]==roadID)
				return i;
		}
		return -1;
	}
ITSMap.prototype.loadSelection = function () {
		this.selected = new Array();
		var strArray = document.pointform.selected.value.split(",");
		for (var i=0; i<strArray.length; i++) {
			if (strArray[i].match(new RegExp("[0-9]+")))
				this.selected[this.selected.length]=parseInt(strArray[i]);
		}
	}
ITSMap.prototype.updateNotified = function (response) {
		this.notified = new Array();
		var strArray = response.split(",");
		for (var i=0; i<strArray.length; i++) {
			if (strArray[i].match(new RegExp("[0-9]+")))
				this.notified[this.notified.length]=parseInt(strArray[i]);
		}
	}
ITSMap.prototype.clicked = function (pos_x, pos_y) {
		for (var i=0; i<this.roads.length; i++) {
			if (pos_x>=this.roads[i][0] && pos_x<=this.roads[i][2]
				&& pos_y>=this.roads[i][1] && pos_y<=this.roads[i][3]) {
				var idx=this.getSelected(i);
				if (idx>=0) {
					this.selected.splice(idx, 1);
				} else {
					this.selected[this.selected.length]=i;
				}
			}
		}
	}
ITSMap.prototype.saveSelection = function () {
		var allStr="";
		for (var i=0; i<this.selected.length; i++) {
			if (i<this.selected.length-1)
				allStr=allStr+this.selected[i]+",";
			else
				allStr=allStr+this.selected[i];
		}
		document.pointform.selected.value=allStr;
	}
	
ITSMap.prototype.paintMap = function () {
		this.jg.drawImage(this.imageURL, 0, 0, 770, 562);
	
		
		for (var i=0; i<this.roads.length; i++) {
			if (this.getSelected(i)>=0) {
				if (this.getNotified(i)>=0) {
					this.jg.setColor("#ff0000");
					this.jg.setStroke(4);
				} else {
					this.jg.setColor("#ffddaa");
					this.jg.setStroke(3);
				}
				this.jg.drawRect(this.roads[i][0], this.roads[i][1],
				this.roads[i][2]-this.roads[i][0], this.roads[i][3]-this.roads[i][1]);
			}
		}
		this.jg.paint();
	}

