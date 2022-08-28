let () =
  let input = Connectivity.Util.input_all stdin in
  let n = 100_000 in
  let gen () =
    let i = ref 0 in
    fun () ->
      try
        let v = input.(!i) in
        incr i;
        v
      with _ -> failwith @@ Format.sprintf "out of input: %d" !i
  in
  let results_timed =
    [
      (* Connectivity.Util.run (module Connectivity.Quickfind_array) n (gen ()); *)
      Connectivity.Util.run (module Connectivity.Quickunion_array) n (gen ());
      Connectivity.Util.run
        (module Connectivity.Quickunion_weighted_array)
        n (gen ());
    ]
  in
  let results = List.map (fun (_, _, pair) -> pair) results_timed in
  match results with
  | [] -> ()
  | _result :: _ ->
      if Connectivity.Util.all_equals results then (
        Connectivity.Util.summarise results_timed;
        Printf.printf "Average distance from the root: %d\n"
        @@ Connectivity.Quickunion_array.average_distance ();
        Printf.printf "Average distance from the root: %d\n"
        @@ Connectivity.Quickunion_weighted_array.average_distance ())
      else print_endline "failed"
