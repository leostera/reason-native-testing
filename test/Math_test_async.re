open Lwt.Infix;
open Alcotest;

let add_minus1_minus1_equals_minus2 = (_switch, ()) => {
  let (waiter, awaker) = Lwt.wait();
  Lwt.async(() => {
    Alcotest.check(int, "-1 + -1 = 3", Math.add(-1, -1), -2);
    Lwt_unix.sleep(0.2) >|= (_ => Lwt.wakeup_later(awaker, ()));
  });
  waiter;
};

let mul_0_by_10_equals_0 = (_switch, ()) => {
  let (waiter, awaker) = Lwt.wait();
  Lwt.async(() => {
    Alcotest.check(int, "0 * 10 = 0", Math.mul(0, 10), 0);
    Lwt_unix.sleep(1.0) >|= (_ => Lwt.wakeup_later(awaker, ()));
  });
  waiter;
};

let test_suite = [
  Alcotest_lwt.test_case("Math.add", `Quick, add_minus1_minus1_equals_minus2),
  Alcotest_lwt.test_case("Math.mul", `Quick, mul_0_by_10_equals_0),
];

Alcotest.run("My Module Tests", [("suite_1", test_suite)]);
