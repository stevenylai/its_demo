package {

	import flash.display.MovieClip;
	//import fl.controls.Button;
	//import fl.controls.Label;
	import flash.display.SimpleButton;
	import flash.text.TextField;

	public class node extends MovieClip {

		private var adjacentnode  = new Array();
		private var posx,posy;
		private var aposx,aposy;
		private var id;
		private var status = 1;
		private var pstatus = 1;
		private var commRange = 200;

		public function node(_id, _x, _y, _status) {
			id = _id;
			posx = _x;
			posy = _y;
			aposx = _x+8.5;
			aposy = _y+8.5;
			status = _status;
			pstatus =  _status;
		}
		public function getid() {
			return id;
		}
		public function setid(_id) {
			id = _id;
		}
		public function getx() {
			return posx;
		}
		public function setx(_x) {
			posx = _x;
		}
		public function gety() {
			return posy;
		}
		public function sety(_y) {
			posy = _y;
		}
		public function getax() {
			return aposx;
		}
		public function setax(_x) {
			aposx = _x;
		}
		public function getay() {
			return aposy;
		}
		public function setay(_y) {
			aposy = _y;
		}
		public function setStatus(_status) {
			status = _status;
		}
		public function getStatus() {
			return status;
		}
		public function getPstatus() {
			return pstatus;
		}
		public function setPstatus(_status) {
			pstatus = _status;
		}
		public function AdjacentNodeSize() {
			return adjacentnode.length();
		}
		public function getAdjacentNode(index) {
			return adjacentnode[index];
		}
		public function getNoAdjacent() {
			return adjacentnode.length;
		}
		public function addAdjacentNode(_node) {

			//if (adjacentnode.indexOf(_node)!=-1) {
			adjacentnode.push(_node);
			//}
		}
		public function removeAdjacentNode( _node) {
			adjacentnode.splice(adjacentnode.indexOf(_node),1);
		}


	}
}