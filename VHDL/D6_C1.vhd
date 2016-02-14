library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;

entity D6_C1 is
	 port(
		 rst : in STD_LOGIC;
		 sel : in STD_LOGIC;
		 clk : in STD_LOGIC;
		 seg1 : out STD_LOGIC_VECTOR(7 downto 0);--hang don vi
		 seg2 : out STD_LOGIC_VECTOR(7 downto 0)--hang chuc
	     );
end D6_C1;

architecture D6_C1 of D6_C1 is
begin		
	process(rst,clk,sel)
	variable temp1:integer range 0 to 10;
	variable temp2:integer range 0 to 10;
	begin
	if (rst='1') then 
		temp1:=0;
		temp2:=0;
	elsif (rising_edge(clk)) then 
		if (sel='1') then
			if (temp1=10) then
				temp1:=0;
				temp2:=temp2+1;
				if (temp2=10) then temp2:=0;
				end if;
			else temp1:=temp1+1;
			end if;
		elsif (sel='0') then
				if(temp1=0) then
					temp1:=9;
					temp2:=temp2-1;
					if (temp2=0) then temp2:=9;
					end if;
				else temp1:=temp1-1;
				end if;
		end if;
	end if;

	case temp1 is
                when 0 => seg1<= x"C0";
                when 1 => seg1<= x"F9";
                when 2 => seg1<= x"A4";
                when 3 => seg1<= x"B0";
                when 4 => seg1<= x"99";
                when 5 => seg1<= x"92";
                when 6 => seg1<= x"82";
                when 7 => seg1<= x"F8";
				when 8 => seg1<= x"80";
                when 9 => seg1<= x"90";
				when others =>NULL;
	end case;
	case temp2 is
                when 0 => seg2<= x"C0";
                when 1 => seg2<= x"F9";
                when 2 => seg2<= x"A4";
                when 3 => seg2<= x"B0";
                when 4 => seg2<= x"99";
                when 5 => seg2<= x"92";
                when 6 => seg2<= x"82";
                when 7 => seg2<= x"F8";
				when 8 => seg2<= x"80";
                when 9 => seg2<= x"90";
				when others =>NULL;
	 end case; 
end process;
end D6_C1;
-- rst= 10kHz; sel=50Khz; clk=20Mhz;