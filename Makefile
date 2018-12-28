.PHONY: test
test:
	dune build @test/runtest-sync
	dune build @test/runtest-async
	dune build @test/runprops
