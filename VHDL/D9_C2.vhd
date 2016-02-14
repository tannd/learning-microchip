library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D9_C2 is
	 port(
		 rst : in STD_LOGIC;
		 clk : in STD_LOGIC;
		 seg : out STD_LOGIC_VECTOR(9 downto 0)
	     );
end D9_C2;

architecture D9_C2 of D9_C2 is
begin
	process(rst,clk)
	variable dem:integer range 0 to 9;
	begin
	if (rst='1') then dem:=0;
	elsif (rising_edge(clk)) then 
			if (dem=8) then dem:=0;
			else dem:=dem+1;
			end if;
	end if;
	case dem is
                when 0 => seg<= "0000000001";
                when 1 => seg<= "0000000010";
                when 2 => seg<= "0000000100";
                when 3 => seg<= "0000001000";
                when 4 => seg<= "0000010000";
                when 5 => seg<= "0000100000";
                when 6 => seg<= "0001000000";
                when 7 => seg<= "0010000000";
				when 8 => seg<= "0100000000";
				when 9 => seg<= "1000000000";
				when others =>NULL;
	end case;
	end process;
												                                                                                                                                                                                                                                                                                                                                                        
end D9_C2;
-- rst= 100Khz; clk=10Mhz;