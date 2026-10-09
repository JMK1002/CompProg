import static org.junit.Assert.*;

import java.util.Arrays;

import org.junit.Test;

/*
 * @Author Vikash Sahu
 * Public Unit Tests for Piece Class
 * Reversi Project
 * Fall 2025
 */

public class PiecePublicTestsFall2025 {

	@Test
	public void testConstructorRow() {
		Piece p = new Piece("d3", Piece.Color.BLACK);
		assertEquals(2, p.getRow());
	}
	
	@Test
	public void testConstructorColumn() {
		Piece p = new Piece("d3", Piece.Color.BLACK);
		assertEquals(3, p.getColumn());
	}
	
	@Test
	public void testConstructorPiece() {
		Piece p = new Piece("d1", Piece.Color.BLACK);
		assertEquals(Piece.Color.BLACK, p.getColor());
	}
	
	@Test
	public void testToString1() {
		Piece p = new Piece(1, 3, Piece.Color.BLACK);
		assertEquals("d2B", p.toString());
	}
	
	@Test
	public void testToString2() {
		Piece p = new Piece(1, 3, Piece.Color.WHITE);
		assertEquals("d2W", p.toString());
	}
	
	@Test
	public void testToString3() {
		Piece p = new Piece(1, 3, Piece.Color.EMPTY);
		assertEquals("d2", p.toString());
	}
	
	@Test
	public void testGetRowAndColFromPosition1() {
		int[] rowCol = Piece.getRowAndColFromPosition("d4");
		assertTrue(Arrays.equals(new int[] {3,3}, rowCol));
	}
	
	@Test
	public void testGetRowAndColFromPosition2() {
		int[] rowCol = Piece.getRowAndColFromPosition("D4");
		assertTrue(Arrays.equals(new int[] {3,3}, rowCol));
	}
	
	@Test
	public void testGetRowAndColFromPosition3() {
		int[] rowCol = Piece.getRowAndColFromPosition("a1");
		assertTrue(Arrays.equals(new int[] {0,0}, rowCol));
	}
	
	@Test
	public void testGetRowAndColFromPosition4() {
		int[] rowCol = Piece.getRowAndColFromPosition("h8");
		assertTrue(Arrays.equals(new int[] {7,7}, rowCol));
	}

	/* 
	 * Below are some public tests for the compareTo method, should
	 * you choose to take on the optional extension.
	 */

	/*@Test
	public void testCompareTo1() {
		Piece p = new Piece("d5", Piece.Color.WHITE);
		Piece p2 = new Piece("a5", Piece.Color.BLACK);
		assertEquals(3, p.compareTo(p2));
	}
	
	@Test
	public void testCompareTo2() {
		Piece p = new Piece("d5", Piece.Color.WHITE);
		Piece p2 = new Piece("a5", Piece.Color.BLACK);
		assertEquals(-3, p2.compareTo(p));
	}
	
	@Test
	public void testCompareTo3() {
		Piece p = new Piece("d5", Piece.Color.WHITE);
		Piece p2 = new Piece("d5", Piece.Color.BLACK);
		assertEquals(0, p.compareTo(p2));
	}
	
	@Test
	public void testCompareTo4() {
		Piece p = new Piece("c3", Piece.Color.BLACK);
		Piece p2 = new Piece("d4", Piece.Color.WHITE);
		assertEquals(-1, p.compareTo(p2));
	}
	
	@Test
	public void testCompareTo5() {
		Piece p = new Piece("C7", Piece.Color.BLACK);
		Piece p2 = new Piece("D4", Piece.Color.WHITE);
		assertEquals(3, p.compareTo(p2));
	}
	
	*/
}