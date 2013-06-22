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
  }
  public void switchTo(Road newRoad) {
    if (this.belongs.cross != null) {
       this.belongs.cross.waiting.remove(this);
    }
    this.belongs.cars.remove(this);
    this.from = this.belongs;
    this.belongs = newRoad;
    this.belongs.cars.add(this);
  }
}
