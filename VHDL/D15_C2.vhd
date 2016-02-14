library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D15_C2 is
	 port(
		 clk : in STD_LOGIC;
		 seg : out STD_LOGIC_VECTOR(7 downto 0)
	     );
end D15_C2;

architecture D15_C2 of D15_C2 is
begin
	process(clk)
	variable dem:integer range 0 to 4;
	begin
	if (rising_edge(clk)) then 
				if (dem=4) then dem:=0;
				else dem:=dem+1;
				end if;
	end if;
	case dem is
		when 0=> seg <="00000000";
		when 1=> seg <="00011000";
		when 2=> seg <="00111100";
		when 3=> seg <="01111110";
		when 4=> seg <="11111111";
		when others=> seg <="XXXXXXXX";
	end case;
	end process;
end D15_C2;
-- clk=5Mhz;