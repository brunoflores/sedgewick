let run (module M : Connectivity.Union_find.S) (pairs : (int * int) list) :
    (int * int) list =
  List.fold_left
    (fun acc pair ->
      match M.find pair with
      | Some pair ->
          M.union pair;
          pair :: acc
      | None -> acc)
    [] pairs

let () =
  let rec input_all ch pairs : (int * int) list =
    match In_channel.input_line ch with
    | Some line -> (
        try
          let pair = Scanf.sscanf line "%d %d" (fun p q -> (p, q)) in
          input_all ch (pair :: pairs)
        with _ -> failwith "failed to parse")
    | None -> pairs
  in
  let input = input_all stdin [] in
  let _ = run (module Connectivity.Quickfind_array) input in
  let _ = run (module Connectivity.Quickunion_array) input in
  ()
