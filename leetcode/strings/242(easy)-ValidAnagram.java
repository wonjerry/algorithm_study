import java.util.HashMap;

public class Anagram {
  public static void main(String[] args) {
    System.out.println(isAnagram("anagram", "nagaram"));
  }

  public static boolean isAnagram(String s, String t) {
    HashMap<Integer, Integer> map = new HashMap();

    s.codePoints().forEach((character) -> {
      if (!map.containsKey(character)) {
        map.put(character, 1);
      } else {
        map.put(character, map.get(character) + 1);
      }
    });

    for (int i = t.length() - 1; i >= 0; i--) {
      int key = t.codePointAt(i);
      if (!map.containsKey(key)) {
        return false;
      }

      int value = map.get(key);
      if (value == 0) {
        return false;
      }

      map.put(key, value - 1);
    }

    return map.values().stream().allMatch((value) -> value == 0);
  }
}
