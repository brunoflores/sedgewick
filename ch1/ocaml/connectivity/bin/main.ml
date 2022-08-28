let pr result = List.iter (fun (p, q) -> Printf.printf "%d %d\n" p q) result

let run (module M : Connectivity.Union_find.S) (pairs : (int * int) list) :
    (int * int) list =
  let res =
    List.fold_left
      (fun acc pair -> if M.find pair then acc else pair :: acc)
      [] pairs
  in
  List.rev res

let all_equals pairs : bool =
  let two_equals (left : (int * int) list) (right : (int * int) list) : bool =
    if List.length left <> List.length right then false
    else List.for_all2 (fun (p1, q1) (p2, q2) -> p1 = p2 && q1 = q2) left right
  in
  let rec all_equals_aux pairs =
    match pairs with
    | [] | _ :: [] -> true
    | left :: right :: rest ->
        if two_equals left right then all_equals_aux (right :: rest) else false
  in
  all_equals_aux pairs

let rec input_all ch pairs : (int * int) list =
  match In_channel.input_line ch with
  | Some line -> (
      try
        let pair = Scanf.sscanf line "%d %d" (fun p q -> (p, q)) in
        input_all ch (pair :: pairs)
      with _ -> failwith "failed to parse")
  | None -> List.rev pairs

let () =
  let input = input_all stdin [] in
  let results =
    [
      run (module Connectivity.Quickfind_array) input;
      run (module Connectivity.Quickunion_array) input;
      run (module Connectivity.Quickunion_weighted_array) input;
    ]
  in
  match results with
  | [] -> ()
  | result :: _ ->
      if all_equals results then pr result else print_endline "failed"
