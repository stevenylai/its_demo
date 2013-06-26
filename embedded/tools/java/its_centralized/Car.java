class Car {
  public final static int ENTERING = 0;
  public final static int LEAVING = 1;

  public int id;
  public boolean stopped;
  public Road from;
  public Road belongs;
  public int speed;
  public int status;
  public Car (int id, Road belongs) {
    this.id = id;
    this.belongs = belongs;
    this.stopped = false;
    System.out.println("Creating car:" + this.toString());
  }
  public void switchTo(Road newRoad) {
      //System.out.println("Switching " + this.toString() + " to " + newRoad.toString());
    if (this.belongs.cross != null) {
	//System.out.println("Removing car from the old intersection");
       this.belongs.cross.waiting.remove(this);
    }
    this.belongs.cars.remove(this);
    this.from = this.belongs;
    this.belongs = newRoad;
    this.belongs.cars.add(this);
  }
  public String toString() {
    return "Car: " + Integer.toString(this.id) + ", on " + this.belongs.toString();
  }
}
