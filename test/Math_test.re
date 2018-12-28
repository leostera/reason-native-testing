open Alcotest;

let add_minus1_minus1_equals_minus2 = () =>
  Alcotest.check(int, "-1 + -1 = 3", Math.add(-1, -1), -2);

let add_2 = () => Alcotest.check(int, "0 + 2 = 2", Math.add(0, 2), 2);

let mul_0_by_10_equals_0 = () =>
  Alcotest.check(int, "0 * 10 = 0", Math.mul(0, 10), 0);

let test_suite = [
  ("Math.add", `Quick, add_minus1_minus1_equals_minus2),
  ("Math.add", `Quick, add_2),
  ("Math.mul", `Quick, mul_0_by_10_equals_0),
];

Alcotest.run("My Module Tests", [("suite_1", test_suite)]);
