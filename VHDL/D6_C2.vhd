library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D6_C2 is
	 port(
		 nut : in STD_LOGIC_VECTOR(3 downto 0);
		 seg : out STD_LOGIC_VECTOR(3 downto 0)
	     );
end D6_C2;

architecture D6_C2 of D6_C2 is
begin
	process(nut)	
	begin
		case nut is
			when "0000" =>seg<="0000";
			when "0001" =>seg<="0001";
			when "0010" =>seg<="0010";
			when "0100" =>seg<="0100";
			when "1000" =>seg<="1000";
			when others =>null;
		end case;
	end process;
end D6_C2;
-- nut = random 0000=>11111 uniform 100ns; chi dung khi mo phong