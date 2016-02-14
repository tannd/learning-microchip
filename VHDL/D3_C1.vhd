library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D3_C1 is
	 port(
		 rst : in STD_LOGIC;
		 sel : in STD_LOGIC;
		 clk : in STD_LOGIC;
		 seg : out STD_LOGIC_VECTOR(7 downto 0)
	     );
end D3_C1;

architecture D3_C1 of D3_C1 is
begin
	process(rst,clk,sel)
	variable dem:integer range 0 to 9;
	begin
	if (rst='1') then dem:=0;
		elsif (rising_edge(clk)) then 
			if (sel='1') then
				if (dem=9) then dem:=0;
				else dem:=dem+1;
				end if;
			elsif (sel='0') then
				if(dem=0) then dem:=9;
				else dem:=dem-1;
				end if;
			end if;
	end if;
	case dem is
                when 0 => seg<= x"C0";
                when 1 => seg<= x"F9";
                when 2 => seg<= x"A4";
                when 3 => seg<= x"B0";
                when 4 => seg<= x"99";
                when 5 => seg<= x"92";
                when 6 => seg<= x"82";
                when 7 => seg<= x"F8";
                when 8 => seg<= x"80";
                when others => seg<= x"90";
	end case;
	end process;
end D3_C1;
-- rst=500Khz; sel=1Mhz; clk=20Mhz;