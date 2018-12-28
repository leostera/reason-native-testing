# Reason Native Testing Examples

Hello! This repo was built during the 13th live-stream of [Reasonable Coding](https://twitch.tv/ostera) to showcase how we can test things with Alcotest (for unit testing purposes) and QuickCheck (for property based testing!).

To run these tests you can clone this repo and run:

```sh
$ opam install alcotest alcotest-lwt lwt qcheck qcheck-alcotest
$ make test
dune build @test/runtest-sync
   Math_test alias test/runtest-sync
   Testing My Module Tests.
   This run has ID `19365BC0-583A-4425-8E34-278995C7D207`.
   [OK]                suite_1          0   Math.add.
   [OK]                suite_1          1   Math.add.
   [OK]                suite_1          2   Math.mul.
   The full test results are available in `/Users/ostera/repos/github.com/ostera/reason-native-testing/_build/default/test/_build/_tests/19365BC0-583A-4425-8E34-278995C7D207`.
   Test Successful in 0.003s. 3 tests run.
   dune build @test/runtest-async
   Math_test_async alias test/runtest-async
   Testing My Module Tests.
   This run has ID `432DB44F-673A-48CD-9908-C7C53BCDAB60`.
   [OK]                suite_1          0   Math.add.
   [OK]                suite_1          1   Math.mul.
   The full test results are available in `/Users/ostera/repos/github.com/ostera/reason-native-testing/_build/default/test/_build/_tests/432DB44F-673A-48CD-9908-C7C53BCDAB60`.
   Test Successful in 0.002s. 2 tests run.
   dune build @test/runprops
   Math_proptest alias test/runprops
   qcheck random seed: 550692747
   Testing Math Tests.
   This run has ID `F1774ABD-0317-49F3-BF0F-F76F610F947F`.
   [OK]                add          0   Addition is commutative.
   [OK]                add          1   Addition has zero (0) as the identity element.
   [OK]                add          2   Addition is distributive.
   [OK]                mul          0   Multiplication has one (1) as the identity element.
   [OK]                mul          1   Multiplication is commutative.
   [OK]                mul          2   Multiplication is distributive.
   The full test results are available in `/Users/ostera/repos/github.com/ostera/reason-native-testing/_build/default/test/_build/_tests/F1774ABD-0317-49F3-BF0F-F76F610F947F`.
   Test Successful in 0.001s. 6 tests run.
```
