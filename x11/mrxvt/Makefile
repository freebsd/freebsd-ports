# New ports collection makefile for:	mrxvt
# Date created:				27 Nov 2004
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	mrxvt
PORTVERSION=	0.3.9
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	materm

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A tabbed version of rxvt

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include" \
		LIBS="${LIBS} -L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=		mrxvt.1
PLIST_FILES=	bin/mrxvt

PORTDOCS=	TIPS README.greek README.menu README.xvt \
		xdefaults-sample.txt xterm.seq mrxvt.vbs

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 500000
IGNORE=		Does not build
.endif

do-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}/${f}
.endfor
	@${INSTALL_PROGRAM} ${WRKSRC}/src/mrxvt ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/doc/mrxvt.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
