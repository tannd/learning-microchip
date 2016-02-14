
library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D11_C2 is
	port(
		 clk:in std_logic;
		 s0,s1 : out STD_LOGIC
	     );
end D11_C2;


architecture D11_C2 of D11_C2 is
begin

	process(clk)
	begin
	  if(clk='1') then s0<='1';s1<='1';
	  else s0<='0';s1<='0';
	  end if;
	end process;

end D11_C2;
-- clk=0.5hz