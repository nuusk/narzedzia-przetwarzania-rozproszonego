typedef string Msg<50>;

program GETINF {
   version Ver1 {
      Msg getmsg(int album)=1;
   } = 1;
} = 0x21000000;
