struct Solution {}


impl Solution {
    pub fn check_valid_grid(grid: Vec<Vec<i32>>) -> bool {
        let mut pos: Vec<(i32, i32)> = Vec::with_capacity(grid.len() * grid.len());
        pos.resize(grid.len() * grid.len(), (0, 0));

        for i in 0..grid.len() {
            for j in 0..grid[i].len() {
                pos[grid[i][j] as usize] = (i as i32, j as i32);
            }
        }

        if pos[0] != (0, 0) { return false; }

        for i in 0..pos.len() - 1 {
            let check = || {
                let moves: Vec<(i32, i32)> = Vec::from([(1, 2), (1, -2), (2, 1), (2, -1), (-1, 2), (-1, -2), (-2, 1), (-2, -1)]);
                for x in moves {
                    if pos[i].0 + x.0 == pos[i + 1].0 && pos[i].1 + x.1 == pos[i + 1].1 {
                        return true;
                    }
                }
                return false;
            };

            if !check() { return false; }
        }
        return true;
    }
}

fn main() {
    println!("{}", Solution::check_valid_grid(
        Vec::from([
            Vec::from([24, 11, 22, 17, 4]),
            Vec::from([21, 16, 5, 12, 9]),
            Vec::from([6, 23, 10, 3, 18]),
            Vec::from([15, 20, 1, 8, 13]),
            Vec::from([0, 7, 14, 19, 2])
        ]
        ))
    );
}
