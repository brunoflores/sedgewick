module type S = sig
  val find : int * int -> (int * int) option
  val union : int * int -> unit
end
