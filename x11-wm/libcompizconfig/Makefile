PORTNAME=	libcompizconfig
PORTVERSION=	0.8.8
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	https://BSDforge.com/projects/source/x11-wm/libcompizconfig/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Alternative configuration system for Compiz

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USES=		gettext gmake gnome libtool:keepla pathfix pkgconfig tar:bzip2
USE_GNOME=	intltool libxml2

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lpthread

OPTIONS_DEFINE=	INOTIFY
OPTIONS_DEFAULT=	INOTIFY
INOTIFY_DESC?=	Enable inotify support

INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
INOTIFY_LDFLAGS=	-linotify

post-patch:
	@echo "OSVERSION=${OSVERSION}"
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'	\
		${WRKSRC}/src/main.c			\
		${WRKSRC}/src/lists.c			\
		${WRKSRC}/src/filewatch.c		\
		${WRKSRC}/src/ini.c			\
		${WRKSRC}/backend/ini.c

post-patch-INOTIFY-off:
	@${REINPLACE_CMD} -e 's|sys/inotify.h||' ${WRKSRC}/configure

post-install:
.for l in compizconfig/backends/libini.so compiz/libccp.so libcompizconfig.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${l}
.endfor

.include <bsd.port.mk>
