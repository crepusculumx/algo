struct Solution {}

impl Solution {
    pub fn queens_attackthe_king(queens: Vec<Vec<i32>>, king: Vec<i32>) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();

        let moves: Vec<(i32, i32)> = Vec::from([(1, 0), (1, 1), (1, -1), (0, 1), (0, -1), (-1, 1), (-1, 0), (-1, -1)]);

        use std::collections::BTreeSet;
        let mut queen_set: BTreeSet<(i32, i32)> = BTreeSet::new();


        for x in queens {
            queen_set.insert((x[0], x[1]));
        }

        for x in moves {
            let mut pos = (king[0], king[1]);
            while pos.0 >= 0 && pos.1 >= 0 && pos.0 < 8 && pos.1 < 8 {
                if queen_set.contains(&pos) {
                    res.push(Vec::from([pos.0, pos.1]));
                    break;
                }
                pos.0 += x.0;
                pos.1 += x.1;
            }
        }
        return res;
    }
}

fn main() {
    Solution::queens_attackthe_king(Vec::new(), Vec::new());
}
