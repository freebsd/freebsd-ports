# New ports collection makefile for:	pawm
# Date created:				2002-08-22
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	pawm
PORTVERSION=	2.2.3
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.pleyades.net/pawm/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Puto Amo Window Manager

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
MAKEFILE=	Makefile.in
MAKE_ARGS=	GCC="${CC}" MAKE.binary="${CC} ${LDFLAGS} -o"

CFLAGS+=	-I. -I${X11BASE}/include -DNDEBUG
LDFLAGS=	-lm -L${X11BASE}/lib -lXpm -lXrandr

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
CFLAGS+=	-Dintmax_t=u_int32_t -Duintmax_t=u_int32_t \
		-Dstrtoimax=strtoll -Dstrtoumax=strtoull \
		-DSIZE_MAX=UINT_MAX
.endif

.if ${X_WINDOW_SYSTEM} == xfree86-3 || defined(WITHOUT_XFT)
CFLAGS+=	-DDISABLE_XFT
.else
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
CFLAGS+=	`pkg-config --cflags xft`
LDFLAGS+=	`pkg-config --libs xft`
.endif

.if defined(WITH_SN)
LIB_DEPENDS+=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
CFLAGS+=	-DENABLE_STARTUP -DSN_API_NOT_YET_FROZEN \
		`pkg-config --cflags libstartup-notification-1.0`
LDFLAGS+=	`pkg-config --libs libstartup-notification-1.0`
.endif

post-patch:
.if ${OSVERSION} < 500000
	@${GREP} -lR "<stdint\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<stdint\.h>|<inttypes.h>|g'
.endif

do-configure:
	@${ECHO_CMD} -n > ${WRKSRC}/config.h
	@${ECHO_CMD} '#define PROJECT "${PORTNAME}"' >> ${WRKSRC}/config.h
	@${ECHO_CMD} '#define VERSION "${PORTVERSION}"' >> ${WRKSRC}/config.h
	@${ECHO_CMD} '#define CONFDIR "${PREFIX}/etc"' >> ${WRKSRC}/config.h
	@${ECHO_CMD} '#define DATADIR "${DATADIR}"' >> ${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pawm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/conf/pawm.conf ${PREFIX}/etc
	@${MKDIR} ${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/data/icons/*.xpm ${DATADIR}/icons
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ii in AUTHORS Changelog GPL INSTALL README
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
