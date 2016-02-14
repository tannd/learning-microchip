library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity D1_C1 is
    Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           sel : in  STD_LOGIC;
           seg : out  STD_LOGIC_VECTOR (7 downto 0));
end D1_C1;

architecture D1_C1 of D1_C1 is
signal temp:STD_LOGIC_VECTOR (3 downto 0);
begin
	process(clk,rst)
	begin
	if(rst='1') then
	temp<="0000";
	elsif(rising_edge(clk)) then
		if(sel='1') then 
			if temp="1001" then
               temp<="0000";
			else temp<=temp+1;
			end if;
		else
			if temp="0000" then
               temp<="1001";
			else temp<=temp-1;
			end if;
		end if;
	end if;
	end process;
	process(clk,temp)
	begin		
		case temp is
                when "0000" => seg<= x"C0";
                when "0001" => seg<= x"F9";
                when "0010" => seg<= x"A4";
                when "0011" => seg<= x"B0";
                when "0100" => seg<= x"99";
                when "0101" => seg<= x"92";
                when "0110" => seg<= x"82";
                when "0111" => seg<= x"F8";
                when "1000" => seg<= x"80";
                when "1001" => seg<= x"90";
				when others =>NULL;
		end case;
	end process;
end D1_C1;
-- rst =100khz, sel=0.5Mhz, clk=20Mhz.
