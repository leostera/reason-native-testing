let add_is_commutative = {
  let f = ((a, b)) => Math.add(a, b) == Math.add(b, a);
  QCheck.Test.make(
    ~count=100,
    ~name="Addition is commutative",
    QCheck.(pair(small_nat, small_nat)),
    f,
  );
};

let add_is_distributive = {
  let f = ((a, (b, c))) =>
    Math.add(a, Math.add(b, c)) == Math.add(Math.add(a, b), c);
  QCheck.Test.make(
    ~count=100,
    ~name="Addition is distributive",
    QCheck.(pair(small_nat, pair(small_nat, small_nat))),
    f,
  );
};

let add_has_an_identity = {
  let f = x => {
    let on_the_left = Math.add(0, x) == x;
    let on_the_right = Math.add(x, 0) == x;
    on_the_left && on_the_right;
  };
  QCheck.Test.make(
    ~count=100,
    ~name="Addition has zero (0) as the identity element",
    QCheck.small_nat,
    f,
  );
};

let mul_has_an_identity = {
  let f = x => {
    let on_the_left = Math.mul(1, x) == x;
    let on_the_right = Math.mul(x, 1) == x;
    on_the_left && on_the_right;
  };
  QCheck.Test.make(
    ~count=100,
    ~name="Multiplication has one (1) as the identity element",
    QCheck.small_nat,
    f,
  );
};

let mul_is_commutative = {
  let f = ((a, b)) => Math.mul(a, b) == Math.mul(b, a);
  QCheck.Test.make(
    ~count=100,
    ~name="Multiplication is commutative",
    QCheck.(pair(small_nat, small_nat)),
    f,
  );
};

let mul_is_distributive = {
  let f = ((a, (b, c))) =>
    Math.mul(a, Math.mul(b, c)) == Math.mul(Math.mul(a, b), c);
  QCheck.Test.make(
    ~count=100,
    ~name="Multiplication is distributive",
    QCheck.(pair(small_nat, pair(small_nat, small_nat))),
    f,
  );
};

let add_test_suite =
  [add_is_commutative, add_has_an_identity, add_is_distributive]
  |> List.map(QCheck_alcotest.to_alcotest);

let mul_test_suite =
  [mul_has_an_identity, mul_is_commutative, mul_is_distributive]
  |> List.map(QCheck_alcotest.to_alcotest);

Alcotest.run(
  "Math Tests",
  [("add", add_test_suite), ("mul", mul_test_suite)],
);
