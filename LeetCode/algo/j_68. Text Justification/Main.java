import java.util.ArrayList;
import java.util.List;

class Solution {

    private String Build(List<String> line, int maxWidth) {
        int blankSum = maxWidth - line.stream().mapToInt(String::length).sum();
        int blankSize = line.size() == 1 ? blankSum : blankSum / (line.size() - 1);
        int blankAdd = line.size() == 1 ? 0 : blankSum % (line.size() - 1);

        StringBuilder res = new StringBuilder();
        res.append(line.get(0));
        if (line.size() == 1) {
            res.append(" ".repeat(blankSum));
        }
        for (int i = 1; i < line.size(); i++) {
            res.append(" ".repeat(blankSize + (i <= blankAdd ? 1 : 0)));
            res.append(line.get(i));
        }
        return res.toString();
    }

    public List<String> fullJustify(String[] words, int maxWidth) {
        List<List<String>> table = new ArrayList<>();

        int curSum = 0;
        List<String> curLine = new ArrayList<>();
        for (String word : words) {
            if (curSum + word.length() > maxWidth) {
                table.add(curLine);
                curLine = new ArrayList<>();
                curSum = 0;
            }
            curLine.add(word);
            curSum += word.length() + 1;
        }
        if (!curLine.isEmpty()) {
            table.add(curLine);
        }
        List<String> res = new ArrayList<>();
        for (int i = 0; i < table.size() - 1; i++) {
            res.add(Build(table.get(i), maxWidth));
        }

        List<String> lastLine = table.get(table.size() - 1);

        StringBuilder lastLineStr = new StringBuilder();
        lastLineStr.append(lastLine.get(0));

        for (int i = 1; i < lastLine.size(); i++) {
            lastLineStr.append(" ");
            lastLineStr.append(lastLine.get(i));
        }

        while (lastLineStr.length() < maxWidth) {
            lastLineStr.append(" ");
        }
        res.add(lastLineStr.toString());
        return res;
    }
}

public class Main {
}
