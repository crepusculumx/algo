import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class FrequencyTracker {

    private final Map<Integer, Integer> cnt = new HashMap<>();

    private final Map<Integer, Set<Integer>> table = new HashMap<>();

    public FrequencyTracker() {

    }

    public void add(int number) {
        if (!cnt.containsKey(number)) {
            cnt.put(number, 0);
        }

        Integer t = cnt.get(number);
        if (t != 0) {
            table.get(t).remove(number);
            if (table.get(t).isEmpty()) {
                table.remove(t);
            }
        }
        t++;
        cnt.put(number, t);
        if (!table.containsKey(t)) {
            table.put(t, new HashSet<>());
        }
        table.get(t).add(number);
    }

    public void deleteOne(int number) {
        if (!cnt.containsKey(number)) {
            return;
        }
        var t = cnt.get(number);
        table.get(t).remove(number);
        if (table.get(t).isEmpty()) {
            table.remove(t);
        }
        t--;
        if (t != 0) {
            cnt.put(number, t);
            if (!table.containsKey(t)) {
                table.put(t, new HashSet<>());
            }
            table.get(t).add(number);
        } else {
            cnt.remove(number);
        }
    }

    public boolean hasFrequency(int frequency) {
        return table.containsKey(frequency);
    }
}

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker obj = new FrequencyTracker();
 * obj.add(number);
 * obj.deleteOne(number);
 * boolean param_3 = obj.hasFrequency(frequency);
 */

public class Main {
}
