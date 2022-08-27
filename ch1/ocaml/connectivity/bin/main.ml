let () =
  let rec read () =
    match In_channel.input_line stdin with
    | Some line ->
        let pair = Scanf.sscanf line "%d %d" (fun p q -> (p, q)) in
        (match Connectivity.Quickfind.connected pair with
        | Some (p, q) -> Printf.printf "%d %d\n" p q
        | None -> ());
        read ()
    | None -> ()
  in
  read ()
