# New ports collection makefile for:	afterstep-1.4.4
# Version required:	1.4.4
# Date created:		1 May 1998
# Whom:			Brett Taylor
#
# $Id: Makefile,v 1.21 1998/05/22 18:50:18 mph Exp $
#

DISTNAME=	AfterStep-1.4.5.0
PKGNAME=	afterstep-1.4.5.3
CATEGORIES=     x11
MASTER_SITES=   ftp://ftp.afterstep.org/pub/attic/
EXTRACT_SUFX=   .tgz

PATCH_SITES=    ftp://ftp.afterstep.org/pub/attic/
PATCHFILES=	AfterStep1450-to-1451.patch.gz AfterStep1451-to-1453.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	brett@peloton.physics.montana.edu

LIB_DEPENDS=    Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=         ${WRKDIR}/AfterStep

IS_INTERACTIVE=	yes
USE_IMAKE=	yes
INSTALL_TARGET=	install install.man
MANCOMPRESSED=	yes

HAS_CONFIGURE=	yes

XMKMF=		$(X11BASE)/bin/xmkmf
pre-configure:
	@${ECHO_MSG} "The interactive portion is asking you about languages"
	@${ECHO_MSG} "and color use by asclock."
pre-patch:
	@${ECHO_MSG} "*******************************************************"
	@${ECHO_MSG} "The source will be patched to use xv to put non-pixmaps"
	@${ECHO_MSG} "on the root window using a tiled format.  If you would"
	@${ECHO_MSG} "prefer a different viewer or the image not to be tiled,"
	@${ECHO_MSG} "please stop the build now and edit patch-aa to your"
	@${ECHO_MSG} "preferred configuration."
	@${ECHO_MSG} "*******************************************************"

pre-build:
	@ cd ${WRKSRC}; ${MAKE} Makefiles

#there's a missing man file for ASSound - touch so we can install without
#removing the ASSound module and breaking something else
pre-install:
	@${TOUCH} ${WRKSRC}/modules/ASSound/ASSound.man

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/afterdoc/afterstepdoc ${PREFIX}/bin/
	${INSTALL_DATA} ${FILESDIR}/monitor_bsd.xpm ${PREFIX}/include/X11/pixmaps/
	@${RM} ${PREFIX}/share/afterstep/*.orig
	@${RM} ${PREFIX}/share/afterstep/feels/*.orig
	@${RM} ${PREFIX}/share/afterstep/looks/*.orig
	@${RM} ${PREFIX}/share/afterstep/non-configurable/desk*/*.orig
	@${RM} ${PREFIX}/share/afterstep/non-configurable/tmp/*.orig
	@${RM} ${PREFIX}/share/afterstep/desktop/icons/*/*.orig
	@${RM} ${PREFIX}/share/afterstep/desktop/buttons/*.orig
	@${ECHO_MSG} "********************************************************"
	@${ECHO_MSG} "HTML docs are included in ${PREFIX}/share/doc/afterstep"
	@${ECHO_MSG} "********************************************************"

.include <bsd.port.mk>
