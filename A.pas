var i,n,a,b,c,d:int64;
begin
readln(n);
readln(a,b);
c:=max(a,b)-1;
d:=max(n-a,n-b);
if (c<=d) then writeln('White') else writeln('Black');
end.