# New ports collection makefile for: Prima
# Date created:        25 Sept 2001
# Whom:                dmitry@karasik.eu.org
#
# $FreeBSD$
#

PORTNAME=	Prima
PORTVERSION=	1.16
PORTREPOCH=	1
CATEGORIES=	x11-toolkits perl5 graphics
MASTER_SITES=	http://www.prima.eu.org/download/
PKGNAMEPREFIX=	p5-

MAINTAINER=	dmitry@karasik.eu.org
COMMENT=	An extensible Perl toolkit for multi-platform GUI development

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

CONFIGURE_ARGS+=	CC="${CC}" CCFLAGS="${CFLAGS}" PREFIX="${PREFIX}" \
			INSTALL_MAN3="${PREFIX}/lib/perl5/${PERL_VERSION}/man/man3" \
			INSTALL_MAN1="${PREFIX}/man/man1"
CONFIGURE_SCRIPT=       Makefile.PL
USE_XPM=		1
USE_XLIB=		1
USE_PERL5=		yes

post-configure:
	@cd ${CONFIGURE_WRKSRC} && ${PERL5} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

test: build
	cd ${WRKSRC} && make test

post-install:
	${STRIP_CMD} ${SITE_PERL}/${PERL_ARCH}/auto/Prima/Prima.so

.include <bsd.port.mk>

.if defined (WITHOUT_XFT)
CONFIGURE_ARGS+=	WITH_XFT=0
.else
LIB_DEPENDS+=		Xft.2:${PORTSDIR}/x11-fonts/libXft
.if defined (WITHOUT_ICONV)
CONFIGURE_ARGS+=	WITH_ICONV=0
.else
USE_ICONV=	yes
.endif
.endif
