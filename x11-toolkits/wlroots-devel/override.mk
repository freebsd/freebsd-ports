WLR_SUFFIX=	-devel
WLR_SOVERSION=	13

LIB_DEPENDS:=	${LIB_DEPENDS:S/wlroots.so/&.${WLR_SOVERSION}/:S/wlroots$/&${WLR_SUFFIX}/}

USES+=		localbase # -isystem
CONFIGURE_ENV+=	PKG_CONFIG_PATH="${LOCALBASE}/wlroots${WLR_SUFFIX}/libdata/pkgconfig"
MAKE_ENV+=	PKG_CONFIG_PATH="${LOCALBASE}/wlroots${WLR_SUFFIX}/libdata/pkgconfig"
