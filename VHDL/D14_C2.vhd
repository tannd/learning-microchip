library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D14_C2 is
	 port(
		 clk : in STD_LOGIC;
		 seg : out STD_LOGIC_VECTOR(7 downto 0)
	     );
end D14_C2;

architecture D14_C2 of D14_C2 is
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
		when 1=> seg <="10000001";
		when 2=> seg <="11000011";
		when 3=> seg <="11100111";
		when 4=> seg <="11111111";
		when others=> seg <="XXXXXXXX";
	end case;
	end process;
end D14_C2;
-- clk=5Mhz;