library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D7_C1 is
	generic (n:integer :=9);
	 port(
		 rst : in STD_LOGIC;
		 clk : in STD_LOGIC;
		 seg1 : out STD_LOGIC_VECTOR(7 downto 0)
	     );
end D7_C1;

architecture D7_C1 of D7_C1 is
begin
	process(rst,clk)
	variable temp:integer range 0 to 9;
	variable num:integer range 0 to 1:=0;
	begin
	if (rst='1') then
		temp:=0;
	elsif (rising_edge(clk)) then 
		if (num = 0) then
			if (temp=n) then
				num:=1;
			else temp:=temp+1;
			end if;
		end if;
		if (num = 1) then
			if (temp=0) then
				num:=0;
			else temp:=temp-1;
			end if;
		end if;
	end if;
	case temp is
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
	end process;
end D7_C1;
--rst=500Khz; clk=20Mhz;