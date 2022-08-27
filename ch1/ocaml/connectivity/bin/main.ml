let connectivity_on_lines (module M : Connectivity.Union_find.S)
    (ch : in_channel) : unit =
  let rec read () =
    match In_channel.input_line ch with
    | Some line ->
        let pair = Scanf.sscanf line "%d %d" (fun p q -> (p, q)) in
        (match M.find pair with
        | Some (p, q) ->
            M.union (p, q);
            Printf.printf "%d %d\n" p q
        | None -> ());
        read ()
    | None -> ()
  in
  read ()

let () = connectivity_on_lines (module Connectivity.Quickfind_array) stdin
