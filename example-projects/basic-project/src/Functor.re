module type Count = {let count: int;};

module type S = {let repeat: (~times: int=?, string) => string;};

module Make = (RC: Count) : S => {
  let rec repeat = (~times=RC.count, str: string) =>
    if (times <= 0) {
      "";
    } else {
      str ++ repeat(~times=times - 1, str);
    };
};