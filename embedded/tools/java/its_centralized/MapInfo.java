import java.util.*;

class MapInfo {
  public static List <int[]> roadInfo;
  static {
    // Start IC, end IC, capacity, startIC of right exit, startIC of straight exit, startIC of left exit, startIC of right entry, startIC of straight entry, startIC of left entry
    roadInfo = new ArrayList <int[]> ();
    roadInfo.add(new int[]{ 6,  7, 2, -1, -1,  7, -1, -1, -1});
    roadInfo.add(new int[]{ 7,  8, 3, -1,  9, 74, -1, -1, 73});
    roadInfo.add(new int[]{74, 72, 2, -1, -1, 61, 57, -1, -1});
    roadInfo.add(new int[]{73, 75, 2, -1, -1,  9,  7, -1, -1});
    roadInfo.add(new int[]{61, 63, 3, -1, -1,  6, -1, -1, -1});
    roadInfo.add(new int[]{ 9, 10, 1, -1, 11, 84, -1, -1, 83});
    roadInfo.add(new int[]{57, 59, 1, -1, 61, 73, -1, -1, 74});
    roadInfo.add(new int[]{84, 82, 2, -1, -1, 57, 53, -1, -1});
    roadInfo.add(new int[]{83, 85, 2, -1, -1, 11,  9, -1, -1});
    roadInfo.add(new int[]{11, 12, 2, -1, 13, 92, -1, -1, 91});
    roadInfo.add(new int[]{53, 55, 2, -1, 57, 83, -1, -1, 84});
    roadInfo.add(new int[]{92, 90, 2, -1, -1, 53, 49, -1, -1});
    roadInfo.add(new int[]{91, 93, 2, -1, -1, 13, 11, -1, -1});
    roadInfo.add(new int[]{13, 14, 2, -1, -1, 15, -1, -1, -1});
    roadInfo.add(new int[]{15, 16, 2, -1, -1, 49, -1, -1, -1});
    roadInfo.add(new int[]{49, 51, 2, -1, 53, 91, -1, -1, 92});
  }
}
