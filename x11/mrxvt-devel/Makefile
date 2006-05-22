# New ports collection makefile for:	mrxvt-devel
# Date created:				24 Apr 2005
# Whom:					Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	mrxvt-devel
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	materm
DISTNAME=	mrxvt-${PORTVERSION}

MAINTAINER=	lars.engels@0x20.net
COMMENT=	Development version of mrxvt

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

CONFLICTS=	mrxvt-0.4.*

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

MAN1=		mrxvt.1

OPTIONS=	XFT "Enable Xft support for fonts" Off \
		JAPANESE "Enable support for Japanese language" Off \
		24BITS "Prefer 24 bits color" On \
		MENUBAR "Enable menubar" On \
		TEXTSHADOW "Enable text shadow" Off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile
.endif

.if defined(WITH_JAPANESE)
CONFIGURE_ARGS+=	--enable-xim --enable-cjk --with-encoding=eucj
.endif

.if defined(WITH_XFT)
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--enable-xft
.endif

.if defined(WITH_24BITS)
CONFIGURE_ARGS+=	--enable-24bits
.endif

.if defined(WITH_MENUBAR)
CONFIGURE_ARGS+=	--enable-menubar
.endif

.if defined(WITH_TEXTSHADOW)
CONFIGURE_ARGS+=	--enable-text-shadow
.endif

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include" \
		LIBS="${LIBS} -L${LOCALBASE}/lib -L${X11BASE}/lib"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mrxvt ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/pixmaps
	@for pixmap in ${WRKSRC}/share/pixmaps/* ; \
	do ${INSTALL_DATA} $$pixmap ${PREFIX}/share/pixmaps/ ; \
	done
	${MKDIR} ${PREFIX}/etc/mrxvt
	${INSTALL_DATA} ${WRKSRC}/share/mrxvtrc ${PREFIX}/etc/mrxvt/mrxvtrc.sample
	${INSTALL_DATA} ${WRKSRC}/share/default.menu ${PREFIX}/etc/mrxvt/default.menu.sample
	${INSTALL_DATA} ${WRKSRC}/share/submenus.menu ${PREFIX}/etc/mrxvt/submenus.menu.sample
	${MKDIR} ${EXAMPLESDIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/share/scripts/mrxvtset.pl ${EXAMPLESDIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/share/scripts/settitle.c ${EXAMPLESDIR}/scripts
	${INSTALL_MAN} ${WRKSRC}/doc/mrxvt.1 ${MANPREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/doc/*.bz2 ${DOCSDIR}
	${BZIP2_CMD} -d ${DOCSDIR}/*.bz2
.endif
	@${ECHO_MSG} "======================================================================="
	@${ECHO_MSG} ""
	@${ECHO_MSG} " Sample configuration files have been installed to ${PREFIX}/etc/mrxvt"
	@${ECHO_MSG} " Useful scripts have been installed to ${EXAMPLESDIR}/scripts"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "======================================================================="

.include <bsd.port.post.mk>
