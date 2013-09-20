# Created by: clsung@dragon2.net
# $FreeBSD$

PORTNAME=	Gtk2
PORTVERSION=	1.243
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	CPAN SF/${PORTNAME:L}-perl/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl module for Gtk+ 2.x graphical user interface library

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Cairo>=0:${PORTSDIR}/graphics/p5-Cairo \
		p5-Pango>=0:${PORTSDIR}/x11-toolkits/p5-Pango \
		p5-Glib2>=0:${PORTSDIR}/devel/p5-Glib2
RUN_DEPENDS=	p5-Pango>=0:${PORTSDIR}/x11-toolkits/p5-Pango \
		p5-Cairo>=0:${PORTSDIR}/graphics/p5-Cairo \
		p5-Glib2>=0:${PORTSDIR}/devel/p5-Glib2

USE_GNOME=	gtk20 pango
USES=		perl5
USE_PERL5=	configure
USE_GMAKE=	yes
CONFIGURE_ENV+=	FORCE_GMAKE=yes
MAKE_ENV+=	LANG=C

NO_STAGE=	yes
post-install:
	@cd ${WRKSRC}/blib/man3 && ${FIND} * -name "*.3" | ${SED} \
		's,^,${MAN3PREFIX:S,^${PREFIX}/,,}/man/man3/,' >> ${TMPPLIST}

.include <bsd.port.mk>
