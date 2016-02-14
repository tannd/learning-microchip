
library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D12_C2 is
	port(
		 clk:in std_logic;
		 s0,s7 : out STD_LOGIC
	     );
end D12_C2;

--}} End of automatically maintained section

architecture D12_C2 of D12_C2 is
begin

	process(clk)
	begin
	  if(clk='1') then s0<='1';s7<='1';
	  else s0<='0';s7<='0';
	  end if;
	end process;

end D12_C2;
-- clk=0.5hz