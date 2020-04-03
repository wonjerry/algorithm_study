import java.util.ArrayList;
import java.util.Arrays;

/**
 * 여기선 ArrayList를 int[]로 바꾸는 방법을 배움
 */

public class CompareStringsByFrequency {
  public int[] numSmallerByFrequency(String[] queries, String[] words) {
    long[] calculatedQueries = Arrays.stream(queries).mapToLong(query -> {
      int min = query.chars().min().orElse('a');
      return query.chars().filter(character -> character == min).count();
    }).toArray();

    long[] calculatedWords = Arrays.stream(words).mapToLong(query -> {
      int min = query.chars().min().orElse('a');
      return query.chars().filter(character -> character == min).count();
    }).toArray();

    ArrayList<Long> answers = new ArrayList();

    for (long calculatedQuery : calculatedQueries) {
      long count = Arrays.stream(calculatedWords).filter(cWord -> cWord > calculatedQuery).count();
      answers.add(count);
    }

    return answers.stream().mapToInt(answer -> answer.intValue()).toArray();
  }
}