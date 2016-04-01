# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libcompizconfig
PORTVERSION=	0.8.8
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Alternative configuration system for Compiz

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_GNOME=	intltool libxml2

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lpthread

OPTIONS_DEFINE=	INOTIFY
OPTIONS_DEFAULT=	INOTIFY
INOTIFY_DESC?=	Enable inotify support

INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
INOTIFY_LDFLAGS=	-linotify

.include <bsd.port.pre.mk>

post-patch:
.if empty(PORT_OPTIONS:MINOTIFY)
	@${REINPLACE_CMD} -e 's|sys/inotify.h||' ${WRKSRC}/configure
.endif
	@echo "OSVERSION=${OSVERSION}"
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'	\
		${WRKSRC}/src/main.c			\
		${WRKSRC}/src/lists.c			\
		${WRKSRC}/src/filewatch.c		\
		${WRKSRC}/src/ini.c			\
		${WRKSRC}/backend/ini.c

post-install:
.for l in compizconfig/backends/libini.so compiz/libccp.so libcompizconfig.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${l}
.endfor

.include <bsd.port.post.mk>
