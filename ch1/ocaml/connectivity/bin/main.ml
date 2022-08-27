let run (module M : Connectivity.Union_find.S) (pairs : (int * int) list) :
    (int * int) list =
  List.fold_left
    (fun acc pair -> if M.find pair then acc else pair :: acc)
    [] pairs

let equals left right : bool =
  if List.length left <> List.length right then false
  else List.for_all2 (fun l r -> l = r) left right

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
  let quickfind_array_res = run (module Connectivity.Quickfind_array) input in
  let quickunion_array_res = run (module Connectivity.Quickunion_array) input in
  if equals quickfind_array_res quickunion_array_res <> true then
    print_endline "FAILED"
