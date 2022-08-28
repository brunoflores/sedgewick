let () =
  let n = 100_000 in
  let gen () = (Random.int n, Random.int n) in
  let results_timed =
    [
      Connectivity.Util.run (module Connectivity.Quickfind_array) n gen;
      Connectivity.Util.run (module Connectivity.Quickunion_array) n gen;
      Connectivity.Util.run
        (module Connectivity.Quickunion_weighted_array)
        n gen;
    ]
  in
  let _ = Connectivity.Util.summarise results_timed in
  (* let _, _, pairs = List.nth results_timed 0 in Connectivity.Util.pr pairs *)
  ()
