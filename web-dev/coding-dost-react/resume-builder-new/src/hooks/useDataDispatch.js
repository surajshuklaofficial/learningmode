import { useContext } from "react";

import { DataDispatchContext } from "../contexts";

const useDataDispatcher = () => (
    useContext(DataDispatchContext)
)

export default useDataDispatcher;