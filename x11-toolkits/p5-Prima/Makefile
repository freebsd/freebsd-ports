# New ports collection makefile for: Prima
# Date created:        25 Sept 2001
# Whom:                dmitry@karasik.eu.org
#
# $FreeBSD$
#

PORTNAME=	Prima
PORTVERSION=	1.07
CATEGORIES=	x11-toolkits perl5 graphics
MASTER_SITES=	http://www.prima.eu.org/download/
PKGNAMEPREFIX=	p5-

MAINTAINER=	dmitry@karasik.eu.org
COMMENT=	An extensible Perl toolkit for multi-platform GUI development

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

CONFIGURE_ARGS+=	CC="${CC}" CCFLAGS="${CFLAGS}" PREFIX="${PREFIX}" \
			INSTALL_MAN3="${PREFIX}/lib/perl5/${PERL_VERSION}/man/man3" \
			INSTALL_MAN1="${PREFIX}/man/man1"
CONFIGURE_SCRIPT=       Makefile.PL
USE_PERL5=		yes

post-configure:
	@cd ${CONFIGURE_WRKSRC} && ${PERL5} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

test: build
	cd ${WRKSRC} && make test

post-install:
	strip ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/auto/Prima/Prima.so

.include <bsd.port.mk>
