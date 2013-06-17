import java.util.*;

class MapInfo {
  public static List <int[]> roadInfo;
  static {
    // Start IC, end IC, capacity, index of exit road 1, index of exit road 2 ...
    roadInfo = new ArrayList <int[]> ();
    roadInfo.add(new int[]{6, 7, 2, 1});
    roadInfo.add(new int[]{7, 8, 3, 2, 5});
    roadInfo.add(new int[]{74, 72, 3, 4});
    roadInfo.add(new int[]{73, 75, 3, 5});
    roadInfo.add(new int[]{61, 63, 3, 0});
    roadInfo.add(new int[]{9, 10, 1, 7, ??});
    roadInfo.add(new int[]{57, 59, 1, 3, 4});
    roadInfo.add(new int[]{84, 82, 2, 6});
    roadInfo.add(new int[]{83, 85, ??});
    roadInfo.add(new int[]{11, 12, ??, ??});
  }
}
