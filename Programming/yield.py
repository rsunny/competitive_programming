def ret_Array(from_ind, page_size):
	arr = list()
	for i in range(page_size):
		arr.append(from_ind + i)
	return arr

if_break = 0

def reader():
	from_ind = 0
	page_size = 5
	while True:
		data = ret_Array(from_ind, page_size)
		# print "In reader ", data
		# yield from data
		for obj in data:
			yield obj
		from_ind = from_ind + page_size
		if if_break >= 1000:
			break

if __name__ == "__main__":
	itr = reader()
	print "I am here", itr
	for obj in itr:
		print "In main ", obj
		if_break = if_break + 50
	print if_break
