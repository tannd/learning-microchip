library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D4_C2 is
	 port(
		 rst : in STD_LOGIC;
		 clk : in STD_LOGIC;
		 seg : out STD_LOGIC_VECTOR(7 downto 0)
	     );
end D4_C2;

architecture D4_C2 of D4_C2 is
begin
	process(rst,clk)
	variable dem:integer range 0 to 8;
	begin
	if (rst='1') then dem:=0;
		elsif (rising_edge(clk)) then 
				if (dem=8) then dem:=0;
				else dem:=dem+1;
				end if;
	end if;
	case dem is
		when 0=> seg <="00000000";
		when 1=> seg <="00000001";
		when 2=> seg <="00000011";
		when 3=> seg <="00000111";
		when 4=> seg <="00001111";
		when 5=> seg <="00011111";
		when 6=> seg <="00111111";
		when 7=> seg <="01111111";
		when others=> seg <="11111111";
	end case;
	end process;

end D4_C2;
--rst=0.5Mhz; clk=20Mhz;